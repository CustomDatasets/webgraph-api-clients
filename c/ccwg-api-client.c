/*
 * ccwg-api-client.c — CommonCrawl WebGraph API client (C + libcurl)
 *
 * COMPILE:
 *   cc -o ccwg-api-client ccwg-api-client.c -lcurl
 *
 * RUN:
 *   ./ccwg-api-client
 *
 * COMPILE AND RUN:
 *   cc -o ccwg-api-client ccwg-api-client.c -lcurl && ./ccwg-api-client
 *
 * REQUIRES:
 *   libcurl development headers and library. HTTPS requires a TLS library
 *   so raw sockets are not practical; libcurl is available on virtually
 *   every Linux, macOS, and FreeBSD system.
 *     macOS:   already installed (ships with the OS)
 *     Debian:  apt install libcurl4-openssl-dev
 *     RHEL:    yum install libcurl-devel
 *     FreeBSD: pkg install curl
 *
 * DESCRIPTION:
 *   Sends a POST request to the CCWG API with the hostnames listed below
 *   (one per line) and prints the raw JSON response to stdout. No JSON
 *   parsing is performed — the response is printed as-is.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


/* --- Hostnames to look up (one per line) --- */

static const char *hostnames = "google.com\nreddit.com";


/* --- API endpoint --- */

static const char *api_url = "https://ccwg-api.customdatasets.com/";


/*--------------------------------------------------------------------------*/
static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t total = size * nmemb;
	(void)userdata;
	fwrite(ptr, 1, total, stdout);
	return total;
}


/*--------------------------------------------------------------------------*/
int main(void)
{
	CURL *curl;
	CURLcode res;
	long http_code = 0;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if (!curl) {
		fprintf(stderr, "Failed to initialize curl\n");
		curl_global_cleanup();
		return 1;
	}

	curl_easy_setopt(curl, CURLOPT_URL, api_url);
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, hostnames);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(hostnames));
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

	res = curl_easy_perform(curl);

	if (res != CURLE_OK) {
		fprintf(stderr, "\ncurl error: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		return 1;
	}

	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
	if (http_code != 200) {
		fprintf(stderr, "\nHTTP %ld\n", http_code);
	}

	printf("\n");

	curl_easy_cleanup(curl);
	curl_global_cleanup();
	return 0;
}
