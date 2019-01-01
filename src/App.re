open BsReactNative;

module Config = {
  type route =
      |Screen(string)
      |Home;

  type navigation = StackNavigator.navigation(route);
};
let str = ReasonReact.string;

let animatedValue = Animated.Value.create(25.0);

module Styles = {
  open Style;
  let container =
    style([flex(1.0), alignContent(Center), justifyContent(Center)]);


  let centerElement = style([textAlign(Center)]);

  let header =
    concat([
      style([fontSize(Animated(animatedValue)), marginBottom(Pt(5.0))]),
      centerElement,
    ]);
  let paragraph = concat([style([]), centerElement]);
};


let animation =
Animated.sequence([|
  Animated.timing(
  ~value=animatedValue,
  ~toValue=`raw(15.0),
  ~duration=500.0,
  (),
  ),
  Animated.timing(
    ~value=animatedValue,
    ~toValue=`raw(25.0),
    ~duration=500.0,
    (),
  ),
|]);

module HomeScreen = {
  open Config;
  let component = ReasonReact.statelessComponent("HomeScreen");

let debuggerString = switch(Platform.os()){
  | Platform.IOS(_) => "Press CMD+R to reload,\n CMD+D or shake for dev menu"
  | Platform.Android => "Double tap R on your keyboard\nor shake for dev menu"
}
  let make = (~navigation:navigation , _children) => {
    ...component,
    didMount: _self => Animated.start(animation, ()),
    render: _self =>
      <View style=Styles.container>
        <Animated.Text style=Styles.header> {str("Welcome to React Native")} </Animated.Text>
        <Text style=Styles.paragraph>
          {str(debuggerString)}
        </Text>
        <Button title="Nav to New Route" onPress={() => navigation.push(Screen("Test String"))}/>
      </View>,
  };
};

module Screen = {
  let component = ReasonReact.statelessComponent("Screen");
  let make = (~heading, _children) =>{
    ...component,
    render: _self =>
    <View style=Styles.container>
        <Text style=Styles.paragraph>
          {str(heading)}
        </Text>
      </View>,
  }
};

module NavigationConfig = {
  open StackNavigator;
  open Config;
  type route = Config.route;
  let initialRoute = Home;

  let getScreen = (route, navigation) =>

  switch(route) {
    | Home => (<HomeScreen navigation/>, screenOptions(~title="Home Screen",()))
    | Screen(heading) => (<Screen heading />, screenOptions(~title=heading, ()))
  };
};

module Stack = StackNavigator.Create(NavigationConfig);

let app = Stack.navigator;