# MACS-Mcstas-Interface
The purpose of this repository is to create a reliable interface between MACS measurements at NCNR in Gaithursburg, MD to Monte-Carlo simulations produced by a McStas simulation originally written by Mads Bertelsen.

The following external installations are required to run this software

1. PyCifRw -> Used to import cif files
2. McStas 2.4+ -> Runs actual simulation
3. DAVE -> Analysis software for MACS data
4. lmfit -> General fitting package for python

Everything else should be self contained in python. The interface works by writing bash scripts which emulate reaul instrument scans.

