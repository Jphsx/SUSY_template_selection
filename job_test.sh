#!/bin/bash
#SBATCH --job-name=conv2                # Job name
#SBATCH --partition=sixhour   # Partition Name (Required)
#SBATCH --mail-type=ALL                 # Mail events (NONE, BEGIN, END, FAIL, ALL)
#SBATCH --mail-user=j342a201@ku.edu     # Where to send mail	
#SBATCH --ntasks=1                      # Run 1 task on one node
#SBATCH --cpus-per-task=24               # Number of threads to use
#SBATCH --mem=2gb                       # Job memory request
#SBATCH --time=0-06:00:00               # Time limit days-hrs:min:sec
#SBATCH --output=conv2_%j.log           # Standard output and error log

#VERSION=$1
#echo 'Version '$VERSION



#MACRO=runmacro2.py
#echo 'Macro '$MACRO

pwd
hostname
date

echo "PATH: "
echo $PATH
 
echo "LD_LIBRARY_PATH"
echo $LD_LIBRARY_PATH

echo "Run SUSY code "

python2 --version

#Need to source ROOT

#. ./setenv.sh
cd /home/t3-ku/janguian/CMSSW_10_6_11_patch1/
eval `scramv1 runtime -sh`



echo $ROOTSYS
 
#MYWDIR=$PWD
MYWDIR="/home/t3-ku/janguian/2l3l/SUSYAnalysis/"
cd ${MYWDIR}
echo "Now in directory "
pwd

echo "Start execution"

#./runmyanalysis.sh ${VERSION} ${MACRO}
./runmyanalysis.sh

date

LIST="TChiWZ_ZToLL"
TREE="SMS_300_270"
MACRO="runmacro.py"
NTHREADS=8
./runmyanalysis.sh ${LIST} ${MACRO} ${TREE} ${TREE}
date

date

exit
