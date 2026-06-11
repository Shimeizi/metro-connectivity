# 🚇 Metro Connectivity

A project developed for the **Analysis and Synthesis of Algorithms** course.

## 📖 Overview

This project analyzes a metro network and computes its **metro connectivity index**.

Given a metro network represented as a multi-graph, the program determines the minimum number of line changes required to travel between stations and calculates the maximum such value across the entire network.

The program also detects disconnected networks and special cases where no line changes are required.

## ✨ Features

* 🚇 Metro network analysis
* 🕸️ Multi-graph representation
* 🔄 Minimum line-change computation
* 📊 Metro connectivity index calculation
* 🔍 Detection of disconnected stations

## 🛠️ Built With

* C++

## ⚙️ Compilation

Compile the project with:

```bash
g++ -std=c++11 -O3 -Wall file.cpp -lm
```

## ▶️ Running

Run the program using standard input:

```bash
./a.out < input.txt > output.txt
```

## 🧪 Testing

Compare the generated output with the expected output:

```bash
diff output.txt expected.txt
```

## 📄 Additional Information

For a detailed description of the project requirements, please refer to the project specification PDF included in this repository.
