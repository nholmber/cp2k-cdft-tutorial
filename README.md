<img src="https://raw.githubusercontent.com/nholmber/cp2k-cdft-tutorial/master/web/logo/cp2k_cdft_logo_400_cropped.png" title="CP2K CDFT Tutorial">

# CP2K CDFT Tutorial

This repository contains the input files used in the [**CP2K tutorial**](https://www.cp2k.org/howto:cdft) for performing constrained density functional theory (CDFT) simulations. CP2K is an open source quantum chemistry package to perform atomistic simulations of solid state, liquid, molecular, periodic, material, crystal, and biological systems.

Please note that this repository contains only the necessary input files to complete the tutorial. Refer to the actual tutorial if you want to learn more about the features and usage of the CDFT implementation in CP2K. A brief introduction to the relevant theory behind the method is also included in the tutorial.

The input files in this repository are divided by category into separate folders. The CDFT input structure and the available features are slightly different in different CP2K versions. Separate tutorial files are provided for CP2K versions 5.1, 6.1, and >7.0. Using the latest CP2K version is strongly recommended.

* tutorial-zn:
  * Learn the basics of running a CDFT calculation with a Becke constraint
  * Learn how to compute the electronic coupling between 2 CDFT states using the MIXED_CDFT module
* tutorial-water:
  * Study the effects of using different Becke weight function formalisms
  * Learn how to use fragment based constraints and to identify when such constraints are useful
* tutorial-h2:
  * Learn how to perform configuration interaction calculations with CDFT (CDFT-CI)
* tutorial-hirshfeld:
  * Same as tutorial-zn but using a Hirshfeld based constraint

If you find the CP2K/CDFT method useful in your work and decide to publish your results, please cite the original implementation papers:

Holmberg, Nico; Laasonen, Kari, *Efficient Constrained Density Functional Theory Implementation for Simulation of Condensed Phase Electron Transfer Reactions*, J. Chem. Theory Comput., 13 (2016), pp 587-601, doi: [10.1021/acs.jctc.6b01085](https://dx.doi.org/10.1021/acs.jctc.6b01085 "Online Version of Publication").

Holmberg, Nico; Laasonen, Kari, *Diabatic model for electrochemical hydrogen evolution based on constrained DFT configuration interaction*, J. Chem. Phys., 149 (2018), 104702, doi: [10.1063/1.5038959](https://dx.doi.org/10.1063/1.5038959 "Online Version of Publication").