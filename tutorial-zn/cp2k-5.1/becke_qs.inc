&QS
  METHOD GPW
  EPS_DEFAULT 1.0E-12
  MAP_CONSISTENT
  EXTRAPOLATION ASPC
  EXTRAPOLATION_ORDER 4
  @IF ( ${BECKE_ACTIVE} == TRUE )
    ! CDFT loop settings
    &CDFT
      TYPE_OF_CONSTRAINT BECKE
      &OUTER_SCF ON
        TYPE BECKE_CONSTRAINT
        EXTRAPOLATION_ORDER 2
        MAX_SCF 10
        ! Convergence threshold
        EPS_SCF 1.0E-3
        ! Optimizer selection:
        ! Now Newton's method with backtracking line search
        OPTIMIZER NEWTON_LS
        ! Optimizer step size
        STEP_SIZE -1.0
        ! Line search settings
        MAX_LS 5
        CONTINUE_LS
        FACTOR_LS 0.5
        ! Finite difference settings for Jacobian matrix
        JACOBIAN_STEP 1.0E-2
        JACOBIAN_FREQ 1 1
        JACOBIAN_TYPE FD1
        JACOBIAN_RESTART FALSE
      &END
    &END CDFT
    &BECKE_CONSTRAINT
      ! Take atomic radii into account?
      ADJUST_SIZE     FALSE
      ATOMIC_RADII    0.63 0.32
      ! Compute Becke charges?
      ATOMIC_CHARGES  TRUE
      ! Constraint strength and target values
      ! Give one value per constraint
      STRENGTH        ${BECKE_STR}
      TARGET          ${BECKE_TARGET}
      ! Cutoff scheme
      CUTOFF_TYPE     ELEMENT
      ELEMENT_CUTOFF  7.0
      ! Perform Becke partitioning only within the space
      ! spanned by constraint atom centered spherical Gaussians
      ! (reduces cost for solvated systems)
      CAVITY_CONFINE  TRUE
      CAVITY_SHAPE    VDW
      EPS_CAVITY      1.0E-7
      IN_MEMORY       TRUE
      SHOULD_SKIP     TRUE
      ! Constraint definitions, each repetition defines a new constraint
      &ATOM_GROUP
        ATOMS 1
        COEFF 1
        CONSTRAINT_TYPE CHARGE
      &END ATOM_GROUP
      ! No constraint applied but calculate charges
      &DUMMY_ATOMS
        ATOMS 2
      &END DUMMY_ATOMS
      ! Print information about CDFT calculation
      &PROGRAM_RUN_INFO ON
        &EACH
          QS_SCF 1
        &END EACH
        COMMON_ITERATION_LEVELS 2
        ADD_LAST NUMERIC
        FILENAME ./${NAME}
      &END PROGRAM_RUN_INFO
    &END BECKE_CONSTRAINT
  @ENDIF
&END QS
