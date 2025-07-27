# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### New Features

* maintenance update for compatibility with tree-sitter 0.25

### Breaking Changes

* calls to the rust `set_language` function need to be updated

## [4.0.0] - 2024-07-26

### New Features

* maintenance update for compatibility with tree-sitter 0.22

### Breaking Changes

* the dependency on tree-sitter 0.22 will break older code

## [3.2.1] - 2024-05-12

This update included a dependency change that was a SEMVER violation and was yanked from crates.io.

### Fixes

* `INPUT` prompt is `str` rather than `sexpr`
    - Apple's documentation uses `sexpr`, but experimentation shows `str` is correct.

## [3.2.0] - 2024-04-21

This update included a dependency change that was a SEMVER violation and was yanked from crates.io.

### New Features

* accepts trailing expressions after `CALL`
    - downstream can provide an option to refuse extended syntax

## [3.1.1] - 2023-05-27

extend the allowed ampersand syntax a little more

## [3.1.0] - 2023-05-21

expands the allowed syntax for ampersand commands

## [3.0.0] - 2023-02-26

### New Features

* string handling is simplified
* scanner output (variable names) no longer has trailing whitespace

### Breaking Changes

* `terminal_str` and `terminal_statement` are eliminated
* assumption of trailing whitespace after variable names will break

## [2.0.4] - 2023-02-12

corrects a bug where `(real)` and `(int)` could erroneously absorb the sign token

## [2.0.3] - 2022-11-05

external scanner is pure C to simplify interactions with various tools

## [2.0.2] - 2022-10-02

license is changed

## [2.0.0] - 2022-07-22

### New Features

* revise variable nodes

### Breaking Changes

* revisit code that analyzes variable nodes

## [1.1.1] - 2022-01-08

Initial release

## [Unreleased] - 2021-10-31

Initial commit