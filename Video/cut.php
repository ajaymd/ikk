<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Jan26"; //Look at the drive and name it exactly that
$classname = $batchdate . "Arrays";//Look at the drive and name it exactly that
$mocksname = $batchdate . "TreeMocks";//Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:27:10", "02:43:20"),
		"Rohit" => array("02:54:14", "03:58:54"),
		"Michelle" => array("04:01:00", "05:10:03"),
		),
"SAMSUNG1" => array(
		"Ganesh" => array("00:04:05", "01:04:40"),
		"Kamakshi" => array("01:07:20", "02:18:45"),
		),
"SAMSUNG2" => array(
		"Maria" => array("00:01:15", "01:03:25"),
		"Mayank" => array("01:03:40", "01:58:25"),
		),
"SAMSUNG3" => array(
		"Zulma" => array("00:06:30", "01:09:49"),
		"Abbas" => array("01:10:00", "02:21:52"),
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
