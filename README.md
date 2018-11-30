
# RealReasonDemo

> This is a React Native application developed in Reason during my ByteConf talk, on 11/30/2018

## Installation

To get started, add the following scripts to your `package.json`:

```json
"scripts": {
  "start": "node node_modules/react-native/local-cli/cli.js start",
  "build": "bsb -make-world -clean-world",
  "watch": "bsb -make-world -clean-world -w"
}
```

Next, run `watch` and `start` scripts from the command line so that both processes are running at the same time. This can be done with `yarn` (e.g. `yarn watch`) or `npm` (e.g. `npm run watch`).

The first script compiles you Reason code in a watch mode, meaning that every change is instantly recompiled.

Second one is a React Native packager that serves the compiled Reason code to the React Native client.

## Breakdown of existing files

The `react-native init` command generates a lot of boilerplate with files that might be not needed for your particular use case. Below is a breakdown of all top-level files to help you decide:

- `.babelrc` - required, for transpiling Javascript files to supported by the mobile engine Javascript version
- `.buckconfig` - optional, configuration files for `Buck`. Can be safely removed in most cases unless you are planning on using it
- `.flowconfig` - optional, used to configure `Flow`, which is a type checker for Javascript. Can be removed as we are writing our code in Reason now
- `.watchmanconfig` - optional, configuration for `Watchman`, which is a Facebook tool for listening to file system changes. This file is not needed, unless you plan on extending its configuration right now
- `app.json` - optional, usually generated when you `eject` from an `Expo` or `create-react-native-app` project. Can be removed without any issues
