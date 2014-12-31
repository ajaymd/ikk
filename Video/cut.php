<?php

date_default_timezone_set('America/Los_Angeles');

$batchdate = "IK3Dec29"; //Look at the drive and name it exactly that
$classname = $batchdate . "Graphs";//Look at the drive and name it exactly that
$mocksname = $batchdate . "DPMocks";//Make sure you append Mocks at the end, for clarity

$sources = array(
"CHRYSLER" => array(
		"Class" => array("00:22:30", "02:02:15"),
		"Vignesh" => array("02:29:30", "03:35:33"),
		),
"ROCKEFEL" => array(
		"Sudhindra" => array("00:10:57", "01:07:10"),
		"Lucian" => array("01:07:15", "01:46:36"),
		),
"TRANSAM" => array(
		"Diana" => array("00:07:08", "01:12:10"),
		"Shikha" => array("01:14:20", "02:14:12"),
		),
"EMPIREST" => array(
		"Vinutha" => array("00:11:00", "01:17:45"),
		"Swarna" => array("01:18:00", "02:18:45"),
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
