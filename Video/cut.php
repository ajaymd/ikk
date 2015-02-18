<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK4Feb16"; //Look at the drive and name it exactly that
$classname = $batchdate . "Final"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "FinalMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(

"SAMSUNG" => array(
		"Mayank1" => array("00:27:00", "01:25:21"),
		"Rohit1" => array("01:25:32", "02:20:00"),
		"Mayank2" => array("02:32:00", "03:38:52"),
		"Rohit2" => array("03:53:35", "04:38:40"),
		),
"SAMSUNG1" => array(
		"Maria1" => array("00:13:07", "01:10:30"),
		"Zulma1" => array("01:12:10", "02:09:05"),
		"Maria2" => array("02:20:48", "03:19:36"),
		"Zulma2" => array("03:37:15", "04:43:21"),
		),
"SAMSUNG2" => array(
		"Abbas1" => array("00:03:13", "00:58:22"),
		"Abbas2" => array("01:08:50", "02:26:27"),
		),
"SAMSUNG3" => array(
		"Ganesh1" => array("00:00:00", "00:51:40"),
		"Michelle1" => array("00:59:53", "02:06:42"),
		"Ganesh2" => array("02:07:30", "03:10:50"),
		"Michelle2" => array("03:28:20", "04:39:46"),
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
