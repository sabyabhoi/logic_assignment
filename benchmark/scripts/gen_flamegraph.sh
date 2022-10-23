#!/bin/bash

perf record -F 6000 --call-graph dwarf ../bin/Profiling/proParser < ./lakh.in 
perf script | ~/workspace/instdir/FlameGraph/stackcollapse-perf.pl | ~/workspace/instdir/FlameGraph/stackcollapse-recursive.pl | ~/workspace/instdir/FlameGraph/flamegraph.pl > out.svg
