<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK5Feb22"; //Look at the drive and name it exactly that
$classname = $batchdate . "GraphsEtAl"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "NoMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
*/
$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:00:00", "02:50:30"),
		));


/*
$sources = array(

"SAMSUNG" => array(
		"Class" => array("00:07:40", "02:02:34"),
		"Radhesh" => array("02:29:50", "03:35:50"),
		"Kevin" => array("03:39:14", "04:39:25"),
		),
"SAMSUNG1" => array(
		"Amit" => array("00:06:19", "01:08:00"),
		"Pulkit" => array("01:08:49", "02:09:07"),
		),
"SAMSUNG2" => array(
		"Ernest" => array("00:01:10", "01:04:07"),
		"Mohit" => array("01:07:30", "02:16:08"),
		),
);
*/


$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";

//$input_prefix = "/Volumes/EXTERNAL/";
$input_prefix = "/Users/sohammehta/Desktop/Upload/";

//$output_prefix = "/Volumes/EXTERNAL/Cuts/" . $batchdate;
$output_prefix = "/Users/sohammehta/Desktop/Upload/Cuts/" . $batchdate;

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
