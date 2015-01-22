<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Jan19"; //Look at the drive and name it exactly that
$classname = $batchdate . "Trees";//Look at the drive and name it exactly that
$mocksname = $batchdate . "RecursionMocks";//Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:00:17", "02:27:10"),
		"Kamakshi" => array("02:52:00", "03:20:08"),
		),
"SAMSUNG1" => array(
		"Rohit" => array("00:00:01", "00:55:08"),
		"Michelle" => array("00:56:40", "02:10:48"),
		),
"SAMSUNG2" => array(
		"Ganesh" => array("00:00:01", "00:35:43"),
		"Zulma" => array("00:56:12", "01:59:48"),
		),
"SAMSUNG3" => array(
		"Maria" => array("00:00:01", "01:00:49"),
		"Abbas" => array("01:01:20", "02:05:48"),
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
