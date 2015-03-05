<?php

date_default_timezone_set('America/Los_Angeles');
$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";

$batchdate = "IK5Mar3"; //Look at the drive and name it exactly that
$classname = $batchdate . "DP"; //Look at the drive and name it exactly that
$mocksname = $batchdate . "ArrayMocks"; //Make sure you append 'Mocks' at the end, for clarity

//$input_prefix = "/Volumes/EXTERNAL/";
$input_prefix = "/Users/sohammehta/Desktop/Upload/";

$output_prefix = "/Volumes/EXTERNAL/Cuts/" . $batchdate;
//$output_prefix = "/Users/sohammehta/Desktop/Upload/Cuts/" . $batchdate;

/* For just class
$sources = array(
"SAMSUNG" => array(
		"Class" => array("00:00:00", "02:50:30"),
		));

*/

$sources = array(

"SAMSUNG" => array(
		"Ernest" => array("00:00:00", "01:08:40"),
		),
"SAMSUNG1" => array(
		"Amit" => array("00:00:00", "01:12:35"),
		),
"SAMSUNG2" => array(
		"Class" => array("00:36:30", "02:30:40"),
		"Radhesh" => array("02:53:58", "04:14:22"),
		"Kevin" => array("04:18:15", "05:33:03"),
		),
);

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
