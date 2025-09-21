question="d-ez"
combine=false
debug="debug"

mkdir -p target
if [ $combine = true ]; then
	question_combined=""$question"-combined"
	python3 expander.py ""$question".cpp"
	mv combined.cpp ""$question_combined".cpp"
	make $debug $question_combined

	echo " " > stats
	if [ $debug ]; then
		/usr/bin/time -o stats -v ./target/"$question_combined-debug" < input.txt  > output.txt
	else
		/usr/bin/time -o stats -v ./target/"$question_combined" < input.txt  > output.txt
	fi
	cat output.txt
	rm output.txt
else
	make $debug $question

	echo " " > stats
	
	if [ $debug ]; then
		/usr/bin/time -o stats -v ./target/"$question-debug" <input.txt > output.txt

	else
		/usr/bin/time -o stats -v ./target/"$question" <input.txt > output.txt
	fi

	cat output.txt
	rm output.txt
fi
