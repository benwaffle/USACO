if [ "$1" == "" ]; then
	echo "Usage: $0 <task>";
	exit;
fi
task=$1
mkdir $task
cp _meta/template.c $task/$task.c
sed -i "" -e "s/\_task\_/$task/g" $task/$task.c
