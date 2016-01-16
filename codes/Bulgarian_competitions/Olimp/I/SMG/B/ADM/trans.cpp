#include <iostream>

using namespace std;

int main()
{
    int P, M, K, M_array_place_left_input, M_array_place_right_input, number_of_cities_with_K, city_transport_found;
    M_array_place_left_input = 0;
    M_array_place_right_input = 1;
    number_of_cities_with_K = 0;
    city_transport_found = 0;

    cin >> P >> M;

//Masiv, v koito zapazvam nomerata na vsichki svurzani gradove
    const int M_array = (M*2) - 1;
    int cities_input[M_array];

//Vhod na svurzanite gradove
    for(int M_copy = M; M_copy != 0; M_copy--)
    {
        cin >> cities_input[M_array_place_left_input] >> cities_input[M_array_place_right_input];
        M_array_place_left_input += 2;
        M_array_place_right_input += 2;
    }

    cin >> K;

    int times_city_found_in_array;
    times_city_found_in_array = 0;

//Promenlivi neobhodimi za tursene
    int being_searched_in_array = 0;
    int search_in_array = 1;
    times_city_found_in_array = cities_input[being_searched_in_array];

//Masiv sus gradovete-transportni vuzli, slagam sushtiq broi elementi, kakto masiva, sus nomerata na vsichki gradove, koito poluchavam ot vhod, zashtoto ne znam kolko sa gradovete-transportni vuzli, no sus sigurnost sa po-malko ot M_array
    int city_transport[M_array];

//Tursene na povtarqshti se gradove
    for(; (being_searched_in_array == (M_array)) && (search_in_array == (M_array + 1)); search_in_array++);
    {
        times_city_found_in_array = cities_input[being_searched_in_array];

        if((cities_input[being_searched_in_array] == cities_input[search_in_array]) && (being_searched_in_array != search_in_array) && (cities_input[being_searched_in_array] != 0))
        {
            times_city_found_in_array++;
            cities_input[search_in_array] = 0;
        }


        if(times_city_found_in_array >= K && search_in_array == M_array)
        {
            number_of_cities_with_K++;
            times_city_found_in_array = 0;
            city_transport[city_transport_found] = cities_input[being_searched_in_array];
            city_transport_found++;
        }

         if(search_in_array == M_array)
        {
            search_in_array = 0;
            cities_input[being_searched_in_array] = 0;
            being_searched_in_array++;
        }


    }

    cout << number_of_cities_with_K <<endl;


}
