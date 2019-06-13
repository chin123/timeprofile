ls $1.*.log.gz | parallel gunzip -k
ls $1.*.log | parallel './logreader/r < {} > {.}.reader'
cat $1*reader > combined.reader
./timeprofile $2 $1.sts < combined.reader 
rm $1.*.log combined.reader $1*reader
