<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Feb09"; //Look at the drive and name it exactly that
$classname = $batchdate . "LL"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "DPMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(
"SAMSUNG" => array(
		"Mayank" => array("00:09:25", "01:12:01"),
		),
"SAMSUNG1" => array(
		"Michelle" => array("00:05:19", "01:15:13"),
		"Abbas" => array("01:16:00", "02:18:50"),
		),
"SAMSUNG2" => array(
		"Class" => array("00:20:27", "02:02:55"),
		"Ganesh" => array("02:40:35", "03:35:32"),
		"Rohit" => array("03:39:40", "04:31:43"),
		),
"SAMSUNG3" => array(
		"Maria" => array("00:08:55", "01:08:00"),
		"Zulma" => array("01:12:20", "02:20:35"),
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
