% MYSTINI(1)

NAME
====

**mystini** — manages INI files

SYNOPSIS
========

| **mystini** \[**-h**|**\--help**|**-v**|**\--version**] \<command> **\--file** FILE \[**\--section** SECTION] \[**\--param** PARAM] \[**\--value** VALUE] \[**\--format** FMT]

DESCRIPTION
===========

Sets / gets or deletes entries of an ini file.

Options
-------

-h, \--help

:   Prints brief usage information.

\--file

: The ini file to process **required**

\--section

: The section of the ini file to process. Required for **set** & **del** commands.

\--param

: The parameter to perform the action on

\--value

: The value to set the param to

\--format

: Select the output format. Valid formats are *sh*, *ini* and *lines*. This is only valid for the **get** command.

-v, \--version

:   Prints the current version number.

Commands
--------

set

: Sets an single value

get

: Gets the entire ini file, a section or a single value using the specified output format

del

: Deletes a single value

BUGS
====

See GitHub Issues: <https://github.com/Sector7CSD/mystini/issues>

AUTHOR
======

Christian Klein <Sector7@gmx.de>
