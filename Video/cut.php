<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK5Feb24"; //Look at the drive and name it exactly that
$classname = $batchdate . "Arrays"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "TreeMocks"; //Make sure you append 'Mocks' at the end, for clarity

/* For just class
$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:00:00", "02:50:30"),
		));

*/

$sources = array(

"SAMSUNG" => array(
		"Class" => array("00:06:49", "01:57:40"),
		"Ernest" => array("02:49:07", "03:52:00"),
		"Kevin" => array("03:56:14", "04:59:18"),
		),
"SAMSUNG1" => array(
		"Nishant" => array("00:00:00", "00:55:43"),
		"Sreekanth" => array("00:55:55", "01:44:15"),
		),
"SAMSUNG2" => array(
		"Radhesh" => array("00:00:00", "00:40:40"),
		),
"SAMSUNG3" => array(
		"Amit" => array("00:01:10", "00:51:40"),
		"Pulkit" => array("01:02:54", "01:54:44"),
		),
);


$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";

$input_prefix = "/Volumes/EXTERNAL/";
//$input_prefix = "/Users/sohammehta/Desktop/Upload/";

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
