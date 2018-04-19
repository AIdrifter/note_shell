earch Shared Libraries
out_dir=out_stack_usage
mkdir -p $out_dir
find . -name "*.su" -type f -exec cp {} ./$out_dir \;
find . -name "*.o" -type f -exec cp {} ./$out_dir \;
./avstack.pl ./$out_dir/*.o > stack_usage_result

# show max
echo -e "\033[33m================== maximum stack usage's function ===================="
sed -n 3p stack_usage_result
echo -e "====================================================================== \033[0m"
