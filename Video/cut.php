<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK3Dec22"; //Look at the drive and name it exactly that
$classname = $batchdate . "Arrays";//Look at the drive and name it exactly that
$mocksname = $batchdate . "TreesMocks";//Make sure you append 'Mocks' at the end, for clarity

$sources = array(
"CHRYSLER" => array(
		"Class" => array("00:02:40", "02:02:06"),
		"Vignesh" => array("02:26:50", "03:33:25"),
		"Diana" => array("03:35:40", "04:41:35"),
		),
"ROCKEFEL" => array(
		"Swarna" => array("00:00:00", "01:01:55"),
		"Lucian" => array("01:06:40", "02:21:30"),
		),
"TRANSAM" => array(
		"Meena" => array("00:00:00", "00:52:15"),
		"Vinutha" => array("01:01:40", "01:57:40"),
		),
"EMPIREST" => array(
		"Sudhindra" => array("00:18:26", "01:20:03"),
		"Shikha" => array("00:00:00", "00:00:01"),
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
