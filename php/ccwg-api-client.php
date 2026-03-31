<?php
declare(strict_types=1);

/*
 * ccwg-api-client.php — CommonCrawl WebGraph API client (PHP + curl)
 *
 * RUN:
 *   php ccwg-api-client.php
 *
 * REQUIRES:
 *   PHP with the curl extension (enabled by default in most distributions)
 *
 * DESCRIPTION:
 *   Sends a POST request to the CCWG API with the hostnames listed below
 *   (one per line) and prints the JSON response with pretty formatting.
 */


// --- Hostnames to look up (one per line) ---

$hostnames = "google.com\nreddit.com";


// --- API endpoint ---

$api_url = 'https://ccwg-api.customdatasets.com/';


// --- Send request ---

$ch = curl_init($api_url);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, $hostnames);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_TIMEOUT, 30);
curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 10);

$response = curl_exec($ch);

if ($response === false) {
	fprintf(STDERR, "curl error: %s\n", curl_error($ch));
	curl_close($ch);
	exit(1);
}

$http_code = (int)curl_getinfo($ch, CURLINFO_HTTP_CODE);
curl_close($ch);

if ($http_code !== 200) {
	fprintf(STDERR, "HTTP %d\n", $http_code);
}


// --- Pretty-print JSON response ---

$json = json_decode($response, true);

if ($json === null) {
	echo $response . "\n";
} else {
	echo json_encode($json, JSON_PRETTY_PRINT) . "\n";
}
