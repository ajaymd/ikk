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
		"Diana" => array("00:00:50", "01:06:20"),
		"Vignesh" => array("01:06:45", "02:05:25"),
		),
"TRANSAM" => array(
		"Meena" => array("00:10:00", "01:17:00"),
		"Swarna" => array("01:26:50", "02:31:20"),
		),
"EMPIREST" => array(
		"Sudhindra" => array("01:01:40", "02:10:30"),
		"Vinutha" => array("02:10:50", "03:19:15"),
		),
);

$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Videos";
$input_prefix = "/Volumes/EXTERNAL/";
$output_prefix = "/Users/sohammehta/Desktop/Videos/" . $batchdate; //"/Volumes/EXTERNAL/Students/";

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

echo "\nSuccessfully started all cutting processes\n";

exit(0);
?>
