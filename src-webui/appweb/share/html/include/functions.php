<?

function hideurl($newurl = "")
{
   if (empty($newurl) )
     $p = "/?p=" . $_GET['p'];
   else
     $p = "$newurl";
   ?>
   <script>
	window.history.pushState('AppWeb', 'AppWeb', '<? echo $p; ?>');
   </script>
   <?
}

// Runs commands through the sudo dispatcher
function run_cmd($cmd)
{
   exec("/usr/local/bin/sudo /usr/local/share/appweb/dispatcher $cmd", $output);
   return $output;
}

function syscache_ins_pbi_list()
{
   exec("/usr/local/bin/syscache ".escapeshellarg("pbi list apps"), $output);
   return $output;
}

?>
