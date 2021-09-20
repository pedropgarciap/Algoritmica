#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Tiempo"
set ylabel "Numero"
plot 'datosFinales.txt' using 1:2 t "Tiempo Real", 'datosFinales.txt' using 1:3 t "Tiempo Estimado" w l
_end_
