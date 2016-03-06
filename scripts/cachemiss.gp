reset
set ylabel 'quantity(times)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'cachemiss.png'

plot [:][250000:] 'cache_miss.txt' using 2:xtic(1) with histogram title 'opt', \
'' using ($0-0.2):($2+100000):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'table size=127'  , \
'' using ($0-0.06):($3+50000):3 with labels title ' ',\
'' using 4:xtic(1) with histogram title '     257'  , \
'' using ($0+0.1):($4):4 with labels title ' ',\
'' using 5:xtic(1) with histogram title '     1031'  , \
'' using ($0+0.4):($5-12000):5 with labels title ' '