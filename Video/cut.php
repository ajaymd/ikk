<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Jan5"; //Look at the drive and name it exactly that
$classname = $batchdate . "Sorting";//Look at the drive and name it exactly that
$mocksname = $batchdate . "WarmupMocks";//Make sure you append 'Mocks' at the end, for clarity

$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:00:00", "02:23:21"),
		"Ganesh" => array("02:25:20", "03:06:56"),
		"Abbas" => array("03:07:45", "03:48:15"),
		),
"SAMSUNG1" => array(
		"Mayank" => array("00:57:20", "01:32:45"),
		"Zulma" => array("01:42:10", "02:16:04"),
		),
"SAMSUNG2" => array(
		"Kamakshi" => array("00:13:29", "00:48:07"),
		"Rohit" => array("00:48:55", "01:20:00"),
		),
"SAMSUNG3" => array(
		"Maria" => array("00:00:40", "00:47:00"),
		"Michelle" => array("00:49:17", "01:25:06"),
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
