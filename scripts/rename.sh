prefix=$1 
file=$2
for name in $file
do
    echo "$name   $prefix $name"
    mv "$name"  "$prefix $name"
done
