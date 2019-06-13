set datafile nofpe_trap
set style data histograms
set style histogram rowstacked
set boxwidth 1 relative
set style fill solid 1.0 border -1
set yrange [0:1.5]
set datafile separator " "
plot 'graph.txt' using 2:xtic(1) title 'Col1', '' using 3 title 'Col2', '' using 4 title 'Col3', '' using 5 title 'Col5', '' using 6 title 'Col6', '' using 7 title 'Col7', '' using 8 title 'Col8'
pause -1 "Hit any key to continue"
