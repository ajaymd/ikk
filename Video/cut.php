<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Feb02"; //Look at the drive and name it exactly that
$classname = $batchdate . "DP"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "ArraysAndStringsMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(
"SAMSUNG" => array(
		"Ganesh" => array("00:00:00", "01:00:30"),
		"Kamakshi" => array("01:00:43", "02:07:10"),
		),
"SAMSUNG1" => array(
		"Mayank" => array("00:00:00", "00:53:00"),
		"Michelle" => array("01:03:25", "02:15:11"),
		),
"SAMSUNG2" => array(
		"Abbas" => array("00:00:00", "01:04:18"),
		"Zulma" => array("01:06:30", "02:15:33"),
		),
"SAMSUNG3" => array(
		"Class" => array("00:00:00", "00:58:41"),
		"Maria" => array("01:32:00", "02:42:07"),
		"Rohit" => array("02:42:10", "03:49:27"),
		),
);


$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";
$input_prefix = "/Volumes/EXTERNAL/";
//$output_prefix = "/Users/sohammehta/Desktop/Videos/" . $batchdate;
$output_prefix = "/Volumes/EXTERNAL/Cuts/" . $batchdate;

foreach ($sources as $source => $parts)
{
	echo "\nStarting $source\n^^^^^^^^^^^^^^^^^\n";

	$input_file = $input_prefix . $classname . '/' . $classname . $source . '.MP4';
	echo "\nInput file: $input_file";

	$parts = $sources[$source];
	
	foreach ($parts as $studentname => $slots)
	{
		if (stripos($studentname, 'Class') === 0)
		{
			$output_file = $output_prefix . '/' . $classname . $studentname . '.MP4';// IK3Dec22DPClass.MP4
		}
		else
		{
			$output_file = $output_prefix . '/' . $mocksname . $studentname . '.MP4';// IK3Dec22LLMocksVinutha.MP4
		}

		//echo "\nOutput path: $output_file";

		$start_time = $slots[0];
		$end_time = $slots[1];

		$duration = (new DateTime($start_time))->diff(new DateTime($end_time));
		$duration_string = $duration->format('%H:%I:%S');

		$capture_output = '/tmp/' . $classname . $source . '_' . $studentname . '_' . time();
		$command = "( cd \"$SCRIPT_DIR\" && ./cut-mp4.sh \"$input_file\" \"$output_file\" $start_time $duration_string ) 1>\"$capture_output\" 2>&1 &";
		echo "\n\tExecuting: $command \n";

		exec($command);
	}
}

echo "\nSuccessfully started all cutting processes. You can monitor with \"watch -n 3 'clear; find $output_prefix -ls'\"\n";

exit(0);
?>
