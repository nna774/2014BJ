set term png size 640,480
set size square
set output "zu.png"
set xrange [-2:2]
set yrange [-2:2]
plot "2-2","3-3"
