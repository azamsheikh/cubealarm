

//cubealarm.php?process=checkalarmstatus
//cubealarm.php?process=checkcubesolvestatus
//cubealarm.php?process=cubesolvestatusupdate&cubesolvestatus=solved
//cubealarm.php?process=alarmstatusupdate&alarmstatus=off



<?php
$servername = "localhost";
$username = "";
$password = "";
$dbname = "";
$do = $_GET['process'];
$alarmstatus = $_GET['alarmstatus'];
$cubesolvestatus = $_GET['cubesolvestatus'];

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


if($do == "checkalarmstatus")
{
$sql = "SELECT alarmstatus FROM rubikscube";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo $row["alarmstatus"];
  }
} else {
  echo "0 results";
}
$conn->close();    
}


if($do == "checkcubesolvestatus")
{
$sql = "SELECT cubesolvestatus FROM rubikscube";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo $row["cubesolvestatus"];
  }
} else {
  echo "0 results";
}
$conn->close();    
}


if($do == "alarmstatusupdate")
{

$sql = "UPDATE rubikscube SET alarmstatus='$alarmstatus' WHERE id=1";

if ($conn->query($sql) === TRUE) {
  echo "Record updated successfully";
} else {
  echo "Error updating record: " . $conn->error;
}

$conn->close(); 
}



if($do == "cubesolvestatusupdate")
{

$sql = "UPDATE rubikscube SET cubesolvestatus='$cubesolvestatus' WHERE id=1";

if ($conn->query($sql) === TRUE) {
  echo "Record updated successfully";
} else {
  echo "Error updating record: " . $conn->error;
}

$conn->close(); 
}













?>