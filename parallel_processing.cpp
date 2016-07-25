/*
 * parallel_processing.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
struct threadelement {
	threadelement(long long ti, int x) :
			time_now(ti), id(x) {
	}
	long long time_now;
	int id;
};
class JobQueue {
private:
	int num_workers_, m;
	vector<int> jobs_;
	vector<threadelement> threads;
	vector<int> assigned_workers_;
	vector<long long> start_times_;

	void WriteResponse() const {
		for (int i = 0; i < jobs_.size(); ++i) {
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
		}
	}

	void ReadData() {
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		threads.resize(num_workers_, threadelement(0, 0));
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		for (int i = 0; i < m; ++i)
			cin >> jobs_[i];
	}

	void AssignJobs() {
		// TODO: replace this code with a faster algorithm.
		vector<long long> next_free_time(num_workers_, 0);
		for (int i = 0; i < jobs_.size(); ++i) {
			int duration = jobs_[i];
			int next_worker = 0;
			for (int j = 0; j < num_workers_; ++j) {
				if (next_free_time[j] < next_free_time[next_worker])
					next_worker = j;
			}
			assigned_workers_[i] = next_worker;
			start_times_[i] = next_free_time[next_worker];
			next_free_time[next_worker] += duration;
		}
	}
	void heapify_thread(int i) {
		int minimum = i;
		int l = 2 * i + 1;
		int r = l + 1;
		if (l < num_workers_) {
			if (threads[l].time_now < threads[minimum].time_now) {
				minimum = l;
			}
			if (threads[l].time_now == threads[minimum].time_now
					&& threads[l].id < threads[minimum].id) {
				minimum = l;
			}
		}
		if (r < num_workers_) {
			if (threads[r].time_now < threads[minimum].time_now) {
				minimum = r;
			}
			if (threads[r].time_now == threads[minimum].time_now
					&& threads[r].id < threads[minimum].id) {
				minimum = r;
			}
		}
		if (minimum != i) {
			swap(threads[i], threads[minimum]);
			heapify_thread(minimum);
		}
	}
	void AssignJobsFast() {
		// TODO: replace this code with a faster algorithm.
		for (int i = 0; i < num_workers_; ++i) {
			threads[i] = threadelement(0, i);
		}
		for (int i = 0; i < jobs_.size(); ++i) {
			start_times_[i] = threads[0].time_now;
			assigned_workers_[i] = threads[0].id;
			threads[0].time_now = threads[0].time_now + jobs_[i];
			heapify_thread(0);
		}
	}

public:
	void Solve() {
		ReadData();
		AssignJobsFast();
		WriteResponse();
	}
};



