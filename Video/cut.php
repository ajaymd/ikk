<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Jan12"; //Look at the drive and name it exactly that
$classname = $batchdate . "Recursion";//Look at the drive and name it exactly that
$mocksname = $batchdate . "SortingMocks";//Make sure you append 'Mocks' at the end, for clarity

$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:04:15", "02:10:33"),
		"Ganesh" => array("02:29:20", "03:23:40"),
		"Maria" => array("03:32:47", "04:23:15"),
		),
"SAMSUNG1" => array(
		"Zulma" => array("00:02:50", "00:57:35"),
		"Mayank" => array("01:07:20", "02:01:45"),
		),
"SAMSUNG2" => array(
		"Abbas" => array("00:02:10", "00:59:00"),
		"Michelle" => array("01:07:40", "02:07:15"),
		),
"SAMSUNG3" => array(
		"Rohit" => array("00:58:25", "01:44:20"),
		),
);

$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";
$input_prefix = "/Volumes/EXTERNAL/";
$output_prefix = "/Users/sohammehta/Desktop/Videos/" . $batchdate;

foreach ($sources as $source => $parts)
{
	echo "\nStarting $source\n^^^^^^^^^^^^^^^^^\n";

	$input_file = $input_prefix . $classname . '/' . $classname . $source . '.MP4';
	echo "\nInput file: $input_file";

	$parts = $sources[$source];
	
	foreach ($parts as $studentname => $slots)
	{
		if ($studentname == 'Class') 
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
