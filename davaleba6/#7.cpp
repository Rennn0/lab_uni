// 6.5 შექმენით Random Walk-ის სიმულაცია 2 განზომილებაში აქციის ფასებისთვის.
// აიღეთ თქვენთვის სასურველი ნებისმიერი კომპანიის აქცია და აქციის დღიური ფასი. შეგიძლიათ ფასები მარტივად იპოვოთ გუგლით: „კომპანიის სახელი“ stock price
// გააკეთეთ აქციების ყოველდღიური ფასის სიმულირება. დავუშვათ, რომ აქციის ფასი მიყვება წრფივ ტრენდს და გამოიხატება შემდეგი პარამეტრებით:
// ფასი(შემდეგი დღე)= a*ფასი(წინა დღე)+b+rand
// a და b პარამეტრები თავად განსაზღვრეთ თქვენ მიერ არჩეულ აქციის ფასსზე დაყრდნობით.
// rand პარამეტრი არის შემთხვევითი პარამეტრი.
// დაითვალეთ, რა იქნება აქციის მოსალოდნელი ფასი და შესაბამისი ალბათოები 4 დღის შემდეგ?
// რომელია ყველაზე მოსალოდნელი ფასი? რა არის იმის ალბათობა, რომ ფასი 50%-ით შემცირდეს?
// აუცილებლად გამოიყენეთ დინამიური მეხსიერება.
// შექმენით შესაბამისი ფუნქციები და არგუმენტებად გადაეცით მისამართები. ყურადღება მიაქციეთ const და non-const პარამეტრებს. სადაც მხოლოდ წაკითხვა გჭირდებათ, მიუთითეთ const.