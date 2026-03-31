#!/usr/bin/env python3
#
# ccwg-api-client.py — CommonCrawl WebGraph API client (Python, stdlib only)
#
# RUN:
#   python3 ccwg-api-client.py
#
# REQUIRES:
#   Python 3 (uses only standard library: urllib.request, json, sys)
#
# DESCRIPTION:
#   Sends a POST request to the CCWG API with the hostnames listed below
#   (one per line) and prints the JSON response with pretty formatting.
#

import json
import sys
import urllib.request
import urllib.error


# --- Hostnames to look up (one per line) ---

HOSTNAMES = "google.com\nreddit.com"


# --- API endpoint ---

API_URL = "https://ccwg-api.customdatasets.com/"


# --- Send request ---

req = urllib.request.Request(
    API_URL,
    data=HOSTNAMES.encode("utf-8"),
    method="POST",
)

try:
    resp = urllib.request.urlopen(req, timeout=30)
    body = resp.read().decode("utf-8")
except urllib.error.HTTPError as e:
    print("HTTP %d" % e.code, file=sys.stderr)
    body = e.read().decode("utf-8")
except urllib.error.URLError as e:
    print("Request failed: %s" % e.reason, file=sys.stderr)
    sys.exit(1)


# --- Pretty-print JSON response ---

try:
    data = json.loads(body)
    print(json.dumps(data, indent=2))
except ValueError:
    print(body)
