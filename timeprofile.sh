time ls $1.*.log.gz | parallel -j200 'pigz -kdc {} | ./logreader/r  > {.}.reader'
#time ls $1.*.log.gz | parallel pigz -kd
#echo "done"
#time ls $1.*.log | parallel './logreader/r < {} > {.}.reader'
#echo "done2"
#echo "starting reader"
#ls $1.*.log | parallel './logreader/r < {} > {.}.reader'
time cat $1*reader > combined.reader
./timeprofile $2 $1.sts < combined.reader 
rm combined.reader $1*reader
