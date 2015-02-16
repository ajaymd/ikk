<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK5Feb10"; //Look at the drive and name it exactly that
$classname = $batchdate . "Recursion"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "SortingMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG1" => array(
		"Class1" => array("00:00:00", "00:36:08"),
		"Class2" => array("00:41:34", "02:28:28"),
		));
*/


$sources = array(

"SAMSUNG" => array(
		"Kevin" => array("00:00:54", "00:39:42"),
		"Sandeep" => array("00:40:56", "01:34:09"),
		),
"SAMSUNG1" => array(
		"Nishant" => array("00:00:00", "00:59:30"),
		"Pulkit" => array("01:00:10", "02:05:35"),
		),
"SAMSUNG2" => array(
		"Class" => array("00:09:50", "02:04:40"),
		"Ernest" => array("02:07:25", "03:10:06"),
		"Amit" => array("03:17:15", "04:23:40"),
		),
"SAMSUNG3" => array(
		"Vijay" => array("00:00:00", "00:53:08"),
		"Srikanth" => array("00:58:10", "02:00:40"),
		),
"SAMSUNG4" => array(
		"Radhesh" => array("00:00:00", "01:03:45"),
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
