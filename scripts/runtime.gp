reset
set ylabel 'average execution time(sec)'
set style fill solid 0.4 border 0
set boxwidth 0.2
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.200]'output.txt' using ($0-0.4):2 with boxes title 'original', \
'' using ($0-0.4):($2+0.01):2 with labels notitle, \
'' using ($0-0.2):3 with boxes title 'optimized'  , \
'' using ($0-0.225):($3+0.0075):3 with labels notitle, \
'' using ($0):4:xtic(1) with boxes title 'string compression'  , \
'' using ($0):($4+0.003):4 with labels notitle, \
'' using ($0+0.2):5 with boxes title 'hashing'  , \
'' using ($0+0.3):($5+0.0015):5 with labels notitle
