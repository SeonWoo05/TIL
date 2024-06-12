$(document).ready(function () {
    // 도서관 검색 버튼 클릭 이벤트
    $("#librarySearch").click(function () { // 도서관 검색 버튼이 클릭되었을 때 실행되는 함수
        var keyword = $("#libraryKeyword").val(); // 입력된 키워드를 가져옴
        var serviceKey = "YEQRDQs6RR%2Bcwt%2BxIBHxDs54Zk5KwuFGkye2QveQRi8rqJcVqYZvyK0KIe07EJGHYVFc4mVPVKUvDSzNv%2BxujQ%3D%3D";

        // 공공데이터 포털의 도서관 정보 API 호출
        $.ajax({
            method: "GET",
            url: "https://apis.data.go.kr/6260000/BusanLibraryInfoService/getLibraryInfo",
            data: {
                serviceKey: decodeURIComponent(serviceKey),
                numOfRows: 10,
                pageNo: 1,
                resultType: "json",
                library_nm: keyword
            },
            dataType: "json",
            success: function (data) {
                var libraries = data.getLibraryInfo.body.items.item;
                displayLibraryInfo(libraries);
            },
            error: function (xhr, status, error) {
                console.error("Status: " + status);
                console.error("Error: " + error);
                console.error(xhr);
                alert("도서관 정보를 가져오는 데 문제가 발생했습니다. 콘솔을 확인하세요.");
            }
        });
    });
    // 책 검색 버튼 클릭 이벤트
    $("#bookSearch").click(function () { // 책 검색 버튼이 클릭되었을 때 실행되는 함수
        var query = $("#bookName").val(); // 입력된 검색어를 가져와서 카카오 API를 통해 책 정보를 검색
        // 카카오 책 정보 API 호출
        $.ajax({
            method: "GET",
            url: "https://dapi.kakao.com/v3/search/book?target=title",
            data: { query: query },
            headers: { Authorization: "KakaoAK ac5d30cc3befc1e7909c34b2c111e43c" }
        })
            .done(function (msg) { // 결과를 받아서 해당 결과를 HTML에 추가
                var bookResults = $("#bookResults");
                bookResults.empty();
                msg.documents.forEach(function (book) {
                    var div = $("<div></div>").addClass("book-info");
                    div.append("<strong>" + book.title + "</strong><br>");
                    div.append("<img src='" + book.thumbnail + "' alt='Thumbnail'><br>");
                    div.append("<span>저자: " + book.authors.join(", ") + "</span><br>");
                    div.append("<span>출판사: " + book.publisher + "</span><br>");
                    div.append("<span>출판일: " + book.datetime.substring(0, 10) + "</span><br>");
                    bookResults.append(div);
                });
            })
            .fail(function (xhr, status, error) {
                console.error("Status: " + status);
                console.error("Error: " + error);
                console.error(xhr);
                alert("책 정보를 가져오는 데 문제가 발생했습니다. 콘솔을 확인하세요.");
            });
    });

    $("#addressSearch").click(function () { // 주소 검색 버튼이 클릭되었을 때 실행되는 함수
        var address = $("#address").val();
        searchAddressToCoordinate(address);
    });

    // 주소 검색 버튼 클릭 이벤트
    $("#address").on("keydown", function (e) {
        if (e.which === 13) {
            var address = $("#address").val();
            searchAddressToCoordinate(address); // 입력된 주소를 가져와서 해당 주소를 좌표로 변환하는 searchAddressToCoordinate() 함수를 호출
        }
    });

    function displayLibraryInfo(libraries) { // 도서관 정보를 표시하는 역할
        var libraryList = $("#libraryList"); // libraries 배열을 받아서 #libraryList에 표시
        libraryList.empty();

        libraries.forEach(function (library) { // 각 도서관의 정보를 <li> 요소에 추가
            var li = $("<li></li>").addClass("library-info");
            li.append("<strong>도서관명: </strong>" + library.library_nm + "<br>");
            li.append("<strong>주소: </strong>" + library.library_addr + "<br>");
            li.append("<strong>전화번호: </strong>" + library.library_tel + "<br>");
            li.append("<strong>홈페이지: </strong><a href='" + library.library_hompage + "' target='_blank'>" + library.library_hompage + "</a>");
            libraryList.append(li);
        });
    }

    function searchAddressToCoordinate(address) { // 입력된 주소를 좌표로 변환하는 역할
        naver.maps.Service.geocode({ // 입력된 주소를 naver.maps.Service.geocode() 메서드를 사용하여 좌표로 변환
            query: address
        }, function (status, response) { // 변환된 결과는 해당 주소의 도로명 주소, 지번 주소, 영문명 주소가 포함된 객체 제공
            if (status === naver.maps.Service.Status.ERROR) {
                return alert('Something Wrong!');
            }
            if (response.v2.meta.totalCount === 0) {
                return alert('올바른 주소를 입력해주세요.');
            }
            var htmlAddresses = [],
                item = response.v2.addresses[0],
                point = new naver.maps.Point(item.x, item.y);
            if (item.roadAddress) {
                htmlAddresses.push('[도로명 주소] ' + item.roadAddress);
            }
            if (item.jibunAddress) {
                htmlAddresses.push('[지번 주소] ' + item.jibunAddress);
            }
            if (item.englishAddress) {
                htmlAddresses.push('[영문명 주소] ' + item.englishAddress);
            }

            insertAddress(item.roadAddress, item.x, item.y); 
        });
    }

    function insertAddress(address, latitude, longitude) { // 변환된 주소와 좌표를 테이블에 삽입
        var mapList = "";
        mapList += "<tr>";
        mapList += "    <td>" + address + "</td>";
        mapList += "    <td>" + latitude + "</td>";
        mapList += "    <td>" + longitude + "</td>";
        mapList += "</tr>";

        $("#mapList").append(mapList);

        var map = new naver.maps.Map('map', { // 지도에 해당 좌표를 중심으로 지도와 마커를 생성하여 표시
            center: new naver.maps.LatLng(longitude, latitude),
            zoom: 14
        });
        var marker = new naver.maps.Marker({
            map: map,
            position: new naver.maps.LatLng(longitude, latitude),
        });
    }
});
