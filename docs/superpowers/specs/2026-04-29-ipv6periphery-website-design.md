---
name: IPv6 Periphery Website Design
description: Static website for ipv6periphery.github.io based on ipv6hitlist.github.io structure, upgraded to Bootstrap 5
type: project
---

## Overview

A static GitHub Pages site for the IPv6 Periphery research project, modeled after ipv6hitlist.github.io with Bootstrap 5 upgrades.

**Paper:** Pruning as Scanning: Towards Internet-Wide IPv6 Network Periphery Discovery (IEEE INFOCOM 2025)
**Tool:** YMap — https://github.com/latteyt/ymap

## Tech Stack

- Bootstrap 5.3 (upgrade from hitlist's Bootstrap 4)
- Highcharts (reused from hitlist)
- jQuery (retained for Highcharts)
- CSS custom properties for theming
- Pure static HTML, no build tools

## Page Sections

1. Title — "Towards Internet-Wide IPv6 Network Periphery Discovery"
2. IPv6 Periphery Service — data service + charts + open access + registration
3. Software and Tools — YMap, Pruning-as-Scanning, buniq
4. Paper (INFOCOM 2025) — abstract, PDF, authors, BibTeX
5. Reproducibility — dataset DOI, scripts
6. Contact — author emails
7. Partners — same logos as ipv6hitlist (placeholder)
8. Data Providers — example.com placeholder

## Visual Upgrades (vs hitlist)

- CSS variables for theme colors and spacing
- Bootstrap 5 navbar with offcanvas mobile menu
- Dark navbar (navbar-dark bg-dark)
- pre/code blocks with light gray background
- Card-based tool list
