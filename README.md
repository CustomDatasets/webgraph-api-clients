# Common Crawl WebGraph API Clients, From CustomDatasets.com

**Project:** https://customdatasets.com
**API:** https://customdatasets.com/webgraph/api/
**Search Tool:** https://customdatasets.com/webgraph/search/

Created by **Ben Wills**
https://benwills.com

---

## Overview

This repository contains example API clients for the **CustomDatasets Common Crawl WebGraph API**, a free public API providing historical ranking data derived from the Common Crawl WebGraph dataset.

The API allows developers to submit domains or hostnames and retrieve time-series ranking metrics including:

* PageRank (raw and normalized)
* Harmonic Centrality (raw and normalized)
* Ranking positions
* Host counts
* Historical snapshot data

The API is intentionally simple:

* No API key
* No authentication
* No SDK required
* Plain HTTP POST
* JSON responses

You can test the API here:

https://customdatasets.com/webgraph/search/

The full API documentation is here:

https://customdatasets.com/webgraph/api/

---

## Repository Contents

This repository includes example clients written in:

* Bash
* C
* Go
* PHP
* Python

Each client demonstrates:

* How to format requests
* How to submit hostnames
* How to parse JSON responses
* How to handle rate limits
* Basic integration patterns

These examples are intentionally simple and dependency-light.

---

## API Summary

Endpoint:

```
POST https://ccwg-api.customdatasets.com/
```

Content type:

```
text/plain
```

Request format:

Plain text hostnames:

```
google.com
github.com
example.com
```

Response format:

JSON containing:

```
results
remaining
```

Example curl:

```
curl -X POST https://ccwg-api.customdatasets.com/ \
  -H "Content-Type: text/plain" \
  -d "google.com"
```

---

## Rate Limits

The free API allows:

* 100 hostname lookups per day
* Up to 10 hostnames per request

If you need bulk data access:

Download the full database:

https://customdatasets.com/webgraph/db/

---

## Data Coverage

Domain data coverage:

2017 → present

Host data coverage:

2020 → present

Earlier host data was excluded due to excessive dangling nodes and limited analytical value.

Both the API and paid database share identical data coverage.

---

## When To Use The API

Use the free API when you need:

* Quick lookups
* Small integrations
* Authority comparisons
* Historical trend checks
* Research tooling
* SEO analysis

Use the full database when you need:

* Bulk analysis
* Unlimited queries
* Local processing
* Data science workflows
* Production pipelines

---

## Philosophy

This API was designed with a few principles:

* No unnecessary barriers
* No forced accounts
* No vendor lock-in
* Simple HTTP interface
* Developer-first usability

If abuse becomes a problem the API may require authentication, so please be considerate with usage.

---

## About The Dataset

The dataset is built from the complete Common Crawl WebGraph history.

The raw Common Crawl data requires significant processing before it becomes useful. This project compiles that data into immediately queryable formats.

Dataset highlights:

* Complete domain history
* Historical rankings
* Normalized scoring systems
* SQLite structured storage
* Query-optimized format

Learn more:

https://customdatasets.com/webgraph/db-docs/

---

## About CustomDatasets

CustomDatasets builds large-scale datasets, databases, and data infrastructure for engineering and marketing teams.

Typical work includes:

* Large scale web scraping
* Competitive intelligence datasets
* Search analysis datasets
* Data enrichment pipelines
* Custom database engineering

Website:

https://customdatasets.com

---

## About The Author

**Ben Wills**

https://benwills.com

Ben is a marketing engineer with 26+ years across marketing and software engineering, specializing in large-scale data systems, search infrastructure, and dataset engineering.

---

## License

MIT License (recommended)

---

## Contributions

Pull requests are welcome for:

* Additional languages
* Performance improvements
* Additional examples
* Error handling improvements

---

## Related Resources

API:

https://customdatasets.com/webgraph/api/

Search tool:

https://customdatasets.com/webgraph/search/

Database:

https://customdatasets.com/webgraph/db/

Database documentation:

https://customdatasets.com/webgraph/db-docs/

---

## Support

For dataset access or custom data engineering work:

https://customdatasets.com

---

## Final Notes

These clients are meant to provide clear integration examples rather than production SDKs.

Production implementations should add:

* Retry logic
* Rate limiting
* Caching
* Validation
* Logging

---

Built by Ben Wills.
