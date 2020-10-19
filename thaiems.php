<?php
$ems_rate = array(
    "currency" => "THB",
    "metric" => "gram",
    "short_metric" => "g",
    "last_update" => "2020-10-19",
    "ems" => array(
        0 => array( 'weight' => 20, 'price' => 32),
        array( 'weight' => 100, 'price' => 37),
        array( 'weight' => 250, 'price' => 42),
        array( 'weight' => 500, 'price' => 52),
        array( 'weight' => 1000, 'price' => 67),
        array( 'weight' => 1500, 'price' => 82),
        array( 'weight' => 2000, 'price' => 97),
        array( 'weight' => 2500, 'price' => 122),
        array( 'weight' => 3000, 'price' => 132),
        array( 'weight' => 3500, 'price' => 142),
        array( 'weight' => 4000, 'price' => 152),
        array( 'weight' => 4500, 'price' => 162),
        array( 'weight' => 5000, 'price' => 172),
        array( 'weight' => 5500, 'price' => 192),
        array( 'weight' => 6000, 'price' => 212),
        array( 'weight' => 6500, 'price' => 232),
        array( 'weight' => 7000, 'price' => 252),
        array( 'weight' => 7500, 'price' => 272),
        array( 'weight' => 8000, 'price' => 292),
        array( 'weight' => 8500, 'price' => 312),
        array( 'weight' => 9000, 'price' => 332),
        array( 'weight' => 9500, 'price' => 352),
        array( 'weight' => 10000, 'price' => 372),
        array( 'weight' => 11000, 'price' => 452),
        array( 'weight' => 12000, 'price' => 492),
        array( 'weight' => 13000, 'price' => 507),
        array( 'weight' => 14000, 'price' => 522),
        array( 'weight' => 15000, 'price' => 537),
        array( 'weight' => 16000, 'price' => 552),
        array( 'weight' => 17000, 'price' => 567),
        array( 'weight' => 18000, 'price' => 582),
        array( 'weight' => 19000, 'price' => 597),
        array( 'weight' => 20000, 'price' => 612)
    )
);
echo json_encode($ems_rate);
?>