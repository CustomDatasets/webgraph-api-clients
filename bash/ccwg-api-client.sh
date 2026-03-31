#!/bin/bash
#
# ccwg-api-client.sh — CommonCrawl WebGraph API client (Bash + curl)
#
# RUN:
#   chmod +x ccwg-api-client.sh
#   ./ccwg-api-client.sh
#
# Or without making executable:
#   bash ccwg-api-client.sh
#
# REQUIRES:
#   curl (pre-installed on virtually all Linux/macOS/FreeBSD systems)
#
# DESCRIPTION:
#   Sends a POST request to the CCWG API with the hostnames listed below
#   (one per line) and prints the raw JSON response to stdout. No JSON
#   parsing is performed — pipe to `jq` or `python3 -m json.tool` if you
#   want pretty output.
#
# EXAMPLE WITH PRETTY PRINTING:
#   ./ccwg-api-client.sh | python3 -m json.tool
#


# --- Hostnames to look up (one per line) ---

HOSTNAMES="google.com
reddit.com"


# --- API endpoint ---

API_URL="https://ccwg-api.customdatasets.com/"


# --- Send request and print response ---

curl -s -X POST "$API_URL" -d "$HOSTNAMES"
echo
