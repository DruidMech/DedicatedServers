import { CognitoIdentityProviderClient, InitiateAuthCommand } from "@aws-sdk/client-cognito-identity-provider";

export const handler = async (event) => {
  const cognitoIdentityProviderClient = new CognitoIdentityProviderClient( { region: process.env.REGION } );

  const { username, password } = event;
  const initiateAuthInput = {
    AuthFlow: "USER_PASSWORD_AUTH",
    ClientId: process.env.CLIENT_ID,
    AuthParameters: {
      USERNAME: username,
      PASSWORD: password
    }
  };
  const initiateAuthCommand = new InitiateAuthCommand(initiateAuthInput);

  try {
    const initiateAuthResponse = await cognitoIdentityProviderClient.send(initiateAuthCommand);
    return initiateAuthResponse;
  } catch(error) {
    return error;
  }
};
