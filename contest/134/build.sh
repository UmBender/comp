question="d"
combine=false
#debug="debug"

mkdir -p target
if [ $combine = true ]; then
	question_combined=""$question"-combined"
	python3 expander.py ""$question".cpp"
	mv combined.cpp ""$question_combined".cpp"
	make $debug $question_combined

	echo " " > stats
	if [ $debug ]; then
		./target/"$question_combined-debug" < input.txt
	else
		./target/"$question_combined" < input.txt
	fi
else
	make $debug $question

	echo " " > stats
	
	if [ $debug ]; then
		./target/"$question-debug" <input.txt

	else
		./target/"$question" <input.txt
	fi

fi
