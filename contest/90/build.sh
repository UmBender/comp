question="d"
combine=false
debug="debug"

if [ $combine = true ]; then
	question_combined=""$question"-combined"
	python3 expander.py ""$question".cpp"
	mv combined.cpp ""$question_combined".cpp"
	make $debug $question_combined

	echo " " > stats
	if [ $debug ]; then
		/usr/bin/time -o stats -v ./"$question_combined-debug" < input.txt  > output.txt
	else
		/usr/bin/time -o stats -v ./"$question_combined" < input.txt  > output.txt
	fi
	cat output.txt
	rm output.txt
else
	make $debug $question

	echo " " > stats
	
	if [ $debug ]; then
		/usr/bin/time -o stats -v ./"$question-debug" <input.txt > output.txt

	else
		/usr/bin/time -o stats -v ./"$question" <input.txt > output.txt
	fi

	cat output.txt
	rm output.txt
fi
