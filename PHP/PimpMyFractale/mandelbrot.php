<?php

// On recupere input et filtre
if (isset($_POST['iteration']))
{
    $_POST['iteration'] = htmlspecialchars($_POST['iteration']);
    $_POST['iteration'] = str_replace(' ', '', $_POST['iteration']);
    $_POST['iteration'] = str_replace(',', '.', $_POST['iteration']);
}
if (isset($_POST['degre']))
{
    $_POST['degre'] = htmlspecialchars($_POST['degre']);
    $_POST['degre'] = str_replace(' ', '', $_POST['degre']);
    $_POST['degre'] = str_replace(',', '.', $_POST['degre']);
}

if (!isset($_POST['iteration']) || $_POST['iteration'] == '' || !is_numeric($_GET['iteration']) || $_GET['iteration'] > 50 || $_GET['iteration'] < 1)
    $iterations_max = 50;
else
    $iterations_max = (int)$_GET['iteration'];

if (!isset($_POST['degre']) || $_POST['degre'] == '' || !is_numeric($_GET['degre']) || $_POST['degre'] < 1)
    $degree = 2;
else
    $degree = (int)$_POST['degre'];

// Variables
$x1 = -2.4;
$x2 = 2.4;
$y1 = -2.4;
$y2 = 2.4;
$zoom = 100;
$size_x = ($x2 - $x1) * $zoom;
$size_y = ($y2 - $y1) * $zoom;
$x = 0;
$y = 0;
$z = 0;

// Creation de l'image et des couleurs
$image = imagecreatetruecolor($size_x, $size_y);
$white = imagecolorallocate($image, 255, 255, 255);
$black  = imagecolorallocate($image, 0, 0, 0);
imagefill($image, 0 ,0 , $white);
$debut = microtime(true);

// On parcours l'image
while ($x < $size_x)
{
    while ($y < $size_y)
    {
        $rc = $x1 + ($x2 - $x1) / $size_x * $x;
        $ic = $y1 + ($y2 - $y1) / $size_y * $y;
        $rz = 0;
        $iz = 0;
        $break = false;

        while ($z < $iterations_max)
        {
            $r = $rz;
            $i = $iz;
            $rz = pow($r * $r + $i * $i, ($degree/2)) * cos($degree * atan2($i, $r)) + $rc;
            $iz = pow($r * $r + $i * $i, ($degree/2)) * sin($degree * atan2($i, $r)) + $ic;
            if ($rz * $rz + $iz * $iz >= 4)
                break;
            $z++;
        }

        if ($z == $iterations_max)
            imagesetpixel($image, $x, $y, $white);
        else
        {
            $degrade = imagecolorallocate($image, $z * 255 / $iterations_max, 0, 0);
            imagesetpixel($image, $x, $y, $degrade);
        }

        $y++;
        $z = 0;
    }
    $x++;
    $y = 0;
}

$temps = round(microtime(true) - $debut, 3);
imagestring($image, 3, 1, 1, "Temps : " . $temps . " secondes", $white);
header('Content-type: image/png');
imagepng($image);
?>
