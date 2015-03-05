<?php

$classname = "IKMarchMar3OM"; //(e.g. IK3Dec28Blah)

$SCRIPT_DIR = "/Users/sohammehta/InterviewKickstart/Video";
$input_folder_prefix = "/Volumes"; //prefix to /volumes/chrysler etc
$input_folder_suffix = "/VIDEO/100VIDEO"; //prefix to /volumes/chrysler etc

$output_prefix = "/Users/sohammehta/Desktop/Upload/" . $classname; // e.g. /Volumes/EXTERNAL/IK3Dec28Blah
//$output_prefix = "/Volumes/EXTERNAL/" . $classname; // e.g. /Volumes/EXTERNAL/IK3Dec28Blah

//$sources = array("SAMSUNG", "SAMSUNG1", "SAMSUNG2", "SAMSUNG3"); //For days when the class is full. Be sure to name them like this. By default, samsung inserts a space between its name and the number, you will have to manually remove it. Otherwise Bash breaks :-P

//$sources = array("SAMSUNG1", "SAMSUNG2", "SAMSUNG");

$sources = array("SAMSUNG");//For days when there is just the class.

foreach ($sources as $source)
{
	echo "\nStarting $source\n^^^^^^^^^^^^^^^^^\n";

	$input_path = $input_folder_prefix . '/' . $source . $input_folder_suffix;
	echo "\nInput path: $input_path";

	$output_path = $output_prefix . '/' . $classname . $source . '.MP4';
	echo "\nOutput path: $output_path";

	unset($output);
	$return_var = 2;
	$output_file = '/tmp/' . $classname . '_' . $source . '_' . time();
 	$command = "( cd \"$SCRIPT_DIR\" && ./concatenate-mp4s.sh \"$input_path\" \"$output_path\" ) 1>\"$output_file\" 2>&1 &";
	echo "\nExecuting: $command \n";

	//$result = exec($command, $output, $return_var);
	$result = exec($command);

/*
	//$result isn't guaranteed to return FALSE like passthru does. Also, $output is useless because the output is piped to a file. And return_var is useless too, because it only checks if the command could be successfully spawned. Downsides of backgrounding the command: No way to check if it started properly. This is useful only in synchronous execution.

	if ($result == FALSE || $return_var != 0)
	{
		echo "\n\nERROR!\n=====\n";
		echo "\nReturn: ".$return_var."\n";
		echo file_get_contents($SCRIPT_DIR . '/' . $output_file);
		
		exit(1);
	}
*/

	echo "\nStarted with $source\n================\n";
	sleep(1);
}

echo "\nSuccessfully started all concatenation processes. You can monitor with \"watch -n 3 'clear; ls -lh $output_prefix'\"\n\n";

exit(0);
?>
