//
// Created by NAMND on 1/8/2021.
//

#include <bits/stdc++.h>
using namespace std;

double dist_origin2dest;
double capacity_fuel_tank, miles_per_gallon, filling_first_time;
double best_cost;

int num_stations;
vector<bool> travelled;
vector<pair<double, double>> stations;
int num_ds = 1;
void backtrack(int i, double remaining, double current_cost)
{
	if (i == num_stations)
	{
		if (best_cost > current_cost)
			best_cost = current_cost;
		return;
	}
	double fuel_needed_for_next_station = (stations[i + 1].first - stations[i].first ) / miles_per_gallon;

	if (capacity_fuel_tank < fuel_needed_for_next_station)
		return;

	if (i == 0)
		remaining -= stations[i].first / miles_per_gallon;
	else
		remaining -= (stations[i].first - stations[i - 1].first) / miles_per_gallon;

	if ((remaining >= (capacity_fuel_tank / 2.0))
		&& (remaining >= fuel_needed_for_next_station)
		&& (i < num_stations))
	{
		backtrack(i + 1, remaining, current_cost);
	}
	else if (remaining < fuel_needed_for_next_station)
	{
		current_cost += (capacity_fuel_tank - remaining) * stations[i].second + 2.0;
		remaining = capacity_fuel_tank;
		backtrack(i + 1, remaining, current_cost);
	}
	else if ((remaining < (capacity_fuel_tank / 2.0) && (remaining >= fuel_needed_for_next_station)))
	{
		for (int j = 0; j <= 1; j++)
		{
			if (j == 0)
				backtrack(i + 1, remaining, current_cost);
			else
			{
				double tmp_remaining = remaining;
				double tmp_current_cost = current_cost;

				current_cost += (capacity_fuel_tank - remaining) * stations[i].second + 2.0;
				remaining = capacity_fuel_tank;

				backtrack(i + 1, remaining, current_cost);

				remaining = tmp_remaining;
				current_cost = tmp_current_cost;
			}
		}
	}
}

int main()
{
	freopen(R"(D:\CompetitivePrograming\UVa\data.inp)", "r", stdin);

	while (true)
	{
		cin >> dist_origin2dest;

		if (int (dist_origin2dest) == -1)
			break;
		cin >> capacity_fuel_tank >> miles_per_gallon >> filling_first_time >> num_stations;

		best_cost = FLT_MAX;
		stations.resize(num_stations);
		travelled.assign(num_stations, false);

		for (int i = 0; i < num_stations; i++)
		{
			cin >> stations[i].first >> stations[i].second;
			stations[i].second /= 100;
		}
		stations.emplace_back(dist_origin2dest, 0);
		backtrack(0, capacity_fuel_tank, filling_first_time);
		cout << "Data Set #" << num_ds << endl;
		cout << "minimum cost = " << best_cost << endl;
		num_ds++;
	}
	return 0;
}
