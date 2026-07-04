
event_inherited();

regions = [
    { code: "us",   location: "USA East — Washington D.C." },
    { code: "usw",  location: "USA West — San José" },
    { code: "ussc", location: "USA South Central — Dallas" },
    { code: "eu",   location: "Europe — Amsterdam" },
    { code: "asia", location: "Asia — Singapore" },
    { code: "jp",   location: "Japan — Tokyo" },
    { code: "au",   location: "Australia — Sydney" },
    { code: "cae",  location: "Canada East — Montreal" },
    { code: "sa",   location: "South America — São Paulo" },
    { code: "kr",   location: "South Korea — Seoul" },
    { code: "in",   location: "India — Chennai" },
    { code: "hk",   location: "Hong Kong" },
    { code: "za",   location: "South Africa — Johannesburg" },
    { code: "tr",   location: "Turkey — Istanbul" },
    { code: "uae",  location: "UAE — Dubai" },
];

regions_index = -1

function region_update()
{
	regions_index ++

	if(regions_index >= array_length(regions))
		regions_index = 0

	code = regions[regions_index].code
	location = regions[regions_index].location

	text = $"{code}: {location}"
}

region_update()

