#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoFinal.eps"
set key left top
set xlabel "Elementos"
set ylabel "Tiempo"
plot 'datosFinalesQuickSort.txt' using 1:2 t "Tiempo Real QuickSort", 'datosFinalesQuickSort.txt' using 1:3 t "Tiempo Estimado QuickSort" w l, 'datosFinalesFusion.txt' using 1:2 t "Tiempo Real Fusion", 'datosFinalesFusion.txt' using 1:3 t "Tiempo Estimado Fusion" w l
_end_

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoQuicksortDivideyVenceras.eps"
set key right bottom
set xlabel "Elementos"
set ylabel "Tiempo"
plot 'tiempoRealesQuickSortDyV.txt' using 1:2 t "Tiempo Real QuickSort" w l
_end_

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoFusionDivideyVenceras.eps"
set key right bottom
set xlabel "Elementos"
set ylabel "Tiempo"
plot 'tiempoRealesFusionDyV.txt' using 1:2 t "Tiempo Real Fusion" w l
_end_




