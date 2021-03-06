&DFT
  @include becke_qs.inc
  BASIS_SET_FILE_NAME BASIS_MOLOPT
  POTENTIAL_FILE_NAME POTENTIAL
  @IF ( ${RESTART} == TRUE )
      WFN_RESTART_FILE_NAME ${WFN_FILE}
  @ENDIF
  CHARGE ${SYS_CHARGE}
  LSD
  &MGRID
    CUTOFF ${PW_CUTOFF}
    NGRIDS 5
    REL_CUTOFF ${PW_REL_CUTOFF}
  &END MGRID
  &POISSON
    PERIODIC NONE
    POISSON_SOLVER WAVELET
  &END POISSON
  &SCF
    @IF ( ${RESTART} == TRUE )
      SCF_GUESS RESTART
    @ENDIF
    @IF ( ${RESTART} == FALSE )
      SCF_GUESS ATOMIC
    @ENDIF
    EPS_SCF 1.0E-6
    CHOLESKY INVERSE_DBCSR
    MAX_SCF 20
    &OT ON
      MINIMIZER DIIS
      PRECONDITIONER FULL_ALL
      ALGORITHM IRAC
    &END OT
    &OUTER_SCF ON
      EPS_SCF 1.0E-6
      MAX_SCF 5
    &END
    &PRINT
      &RESTART ON
        FILENAME ./${NAME}
        BACKUP_COPIES 2
        COMMON_ITERATION_LEVELS 1
        &EACH
          QS_SCF 0
        &END EACH
      &END RESTART
      &RESTART_HISTORY OFF
      &END RESTART_HISTORY
    &END PRINT
  &END SCF

  &XC
    &XC_FUNCTIONAL PBE
    &END XC_FUNCTIONAL
  &END XC
  &PRINT
    &MULLIKEN ON
    &END MULLIKEN
    &LOWDIN ON
    &END LOWDIN
    @IF ( ${SAVE_CUBE} == TRUE )
      &E_DENSITY_CUBE ON
        ! Note the stride must be 1 1 1
        STRIDE 1 1 1
      &END E_DENSITY_CUBE
    @ENDIF
  &END PRINT
&END DFT
&PRINT
  &FORCES OFF
  &END
  &GRID_INFORMATION
  &END
&END